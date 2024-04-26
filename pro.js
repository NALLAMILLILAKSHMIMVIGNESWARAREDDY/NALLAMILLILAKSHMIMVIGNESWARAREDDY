const express=require('express');
const app=express();
const session=require('express-session');
const bcrypt=require('bcryptjs');
const mongoose=require('mongoose');
const fs=require('fs');
const fileupload=require('express-fileupload');
app.use(express.static('public'));
app.listen(3000,()=>{
    console.log("server running sucessfuly..!!");
})
app.set('views', './views');
app.set('view engine', 'pug');
app.use(express.json());
app.use(session({
    secret: 'your-secret-key',
    resave: false,
    saveUninitialized: true
}));
app.use((req, res, next) => {
    res.setHeader('Cache-Control', 'no-cache, no-store, must-revalidate');
    res.setHeader('Pragma', 'no-cache');
    res.setHeader('Expires', '0');
    next();
});

app.use(express.urlencoded());
app.use(fileupload());
let b=mongoose.connect('mongodb://127.0.0.1:27017/onlinexamportal');
b.then((info)=>{
    console.log("connected");
})
b.catch((info)=>{
    console.log("notconnected");
})
let cseschema=new mongoose.Schema({
    user:String,
    password:String,
    pin:String,
})
const customIdType = new mongoose.Schema({
    type: {
      type: String,
      required: true
    }
  }, { unique: true });
let csemodel=new mongoose.model('csedata',cseschema,'registerddata');
const questionSchema = new mongoose.Schema({
    _id: customIdType,
    question: String,
    options: [String],
    correct_answer_index: Number
  });
const questionModel = mongoose.model('csedata1', questionSchema, 'questionpaper');
const submittedAnswersSchema = new mongoose.Schema({
    user: String,
    answers: [Number], // Array containing indices of chosen answers
    score: Number
});

const SubmittedAnswers = mongoose.model('SubmittedAnswers', submittedAnswersSchema);
app.get('/home',(req,res)=>{
    res.sendFile(__dirname+'/public/start.html');
})
app.post('/auth', async(req, res) => {
    if (req.body.pass !== req.body.cpass) {
        const alertScript = `
            <script>
                alert("Password and Confirm Password do not match");
                window.location.href = "/signup.html";
            </script>
        `;
        return res.send(alertScript);
    }
    const passwordRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[!@#$%^&*()_+}{"':;?/<>.,]).{10,}$/;
    if (!passwordRegex.test(req.body.pass)) {
        const alertScript = `
            <script>
                alert("Password must be at least 10 characters long and contain at least one lowercase letter, one uppercase letter, one number, and one special character");
                window.location.href = "/signup.html"; // Redirect back to signup page
            </script>
        `;
        return res.send(alertScript);
    }
    const{name,pass,pin}=req.body;
    const hashedpassword=await bcrypt.hash(pass,10);
    const m = new csemodel({
        user:name,
        password:hashedpassword,
        pin:pin
    });
    await m.save().then((info) => {
        res.sendFile(__dirname + '/public/login.html');
        let pic = req.files.file;
        uploadpath = __dirname + '/public/images/' + pic.name;
        pic.mv(uploadpath, err => {
            if (err) {
                return res.send(err);
            }
            fs.rename(uploadpath, __dirname + '/public/images/' + req.body.name + '.jpg', (error) => {
                console.log(error);
            });
        });
    }).catch((error) => {
        console.error("Error saving data to MongoDB:", error);
        res.status(500).send("Error saving data to MongoDB");
    });
});
app.post('/check',async(req,res)=>{
    const{name1,pass1}=req.body;
    const user=await csemodel.findOne({user:name1});
    if(!user){
        res.status(400).send("no user found");
    }
    const passwordmatch= await bcrypt.compare(pass1,user.password)
    if(passwordmatch){
        req.session.user = name1;
        res.sendFile(__dirname + '/public/main.html');
    }
    else{
        res.sendFile(__dirname + '/public/login.html');
    }
})
app.get('/startexam', async (req, res,next) => {
    const user = req.session.user;
    if (!user) {
        return res.redirect('/login.html'); // Redirect user to login page if not logged in
    }
    if (!req.session.questions) 
    {
    try {
        const previousAnswers = await SubmittedAnswers.findOne({ user: user });
        if (previousAnswers) {
            return res.send("You have already taken the exam."); 
        }
        const questions = await questionModel.aggregate([{ $sample: { size: 10 } }]);
        req.session.questions = questions;
        // res.render('exam', { questions: req.session.questions });
    } catch (error) {
        console.error("Error fetching previous answers or questions:", error);
        res.status(500).send("Error fetching previous answers or questions");
    }
}
    res.render('exam', { questions: req.session.questions });
    next();
});

// app.get('/startexam', async (req, res,next) => {
//     if (!req.session.questions) {
//         try {
//             const questions = await questionModel.aggregate([{ $sample: { size: 10 } }]);
//             req.session.questions = questions;
//         } catch (error) {
//             console.error("Error fetching questions from MongoDB:", error);
//             res.status(500).send("Error fetching questions from MongoDB");
//         }
//     }
//     res.render('exam', { questions: req.session.questions });
//     next();
// });
app.post('/submit-answers', async (req, res) => {
    const answers = req.body;
    let score = 0;
    try {
        const questions = req.session.questions;
        if (!questions) {
            return res.redirect('/startexam');
        }
        for (let i = 0; i < questions.length; i++) {
            let qnum = `question${i}`;
            const userAnswer = parseInt(answers[qnum]);
            if (userAnswer === questions[i].correct_answer_index) {
                score++;
            }
        }
        const user = req.session.user; // Get the logged-in user
        const submittedAnswers = new SubmittedAnswers({
            user: user,
            answers: Object.values(answers).map(Number), // Convert answers to an array of numbers
            score: score
        });
        await submittedAnswers.save(); // Save submitted answers to the database
        res.render('results', { score: score });
    } catch (error) {
        console.error("Error submitting answers:", error);
        res.status(500).send("Error submitting answers");
    }
});
app.get('/logout', (req, res) => {
    req.session.destroy((err) => {
      if (err) {
        console.error("Error destroying session:", err);
        res.status(500).send("Error destroying session");
      } else {
        res.clearCookie('connect.sid'); // Clear the session cookie
        res.redirect('/home');
      }
    });
  });
 app.get('/viewprofile', async (req, res) => {
    file = '/images/' + req.session.user + '.jpg';
    const user = await csemodel.findOne({ user: req.session.user });
    let score = 0; // Default score if no previous answers found
    const previousAnswers = await SubmittedAnswers.findOne({ user: req.session.user });
    if (previousAnswers) {
        score = previousAnswers.score;
    }
    res.render('sample', { name: req.session.user, file, pin: user.pin, score });
});
app.get('/viewscore',async (req,res)=>{
    let score = 0; // Default score if no previous answers found
    const previousAnswers = await SubmittedAnswers.findOne({ user: req.session.user });
    if (previousAnswers) {
        score = previousAnswers.score;
    }
    res.render('results', { score: score });
})

