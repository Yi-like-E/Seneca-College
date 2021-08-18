/************************************************************************ *********
* WEB322 – Assignment 03
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students. *
* Name: ____YiHsun Lee___ Student ID: _129713202_ Date: ___2021/June/25___ *
* Online (Heroku) Link: _____https://mighty-sierra-89111.herokuapp.com______
* ********************************************************************************/

var express = require("express");
var app = express(); // to access all the libraries that express provides
app.use(express.static('public')); // to access css site.css
var path = require("path"); // to accept files
const data = require("./data-service.js"); // responsible to read json files
const multer = require("multer");
const fs = require("fs");
const bodyParser = require("body-parser");

app.use(express.urlencoded({extended: true})); // bodyParser module

var HTTP_PORT = process.env.PORT || 8080;

function onHTTPStart(){
    console.log("Express http server is listening on PORT: " + HTTP_PORT);
};

// create the home page
app.get("/", function(req, res){
    res.sendFile(path.join(__dirname, "/views/home.html"));
});

// create an about page
app.get("/about", function(req, res){
    res.sendFile(path.join(__dirname, "/views/about.html"));
});

// create an addEmployee page
app.get("/employees/add", function(req, res){
    res.sendFile(path.join(__dirname, "/views/addEmployee.html"));
});

app.post("/employees/add", (req, res)=>{
    data.addEmployee(req.body).then(() =>{
        res.redirect("/employees");
    })
})

// create an addImage page
app.get("/images/add", function(req, res){
    res.sendFile(path.join(__dirname, "/views/addImage.html"));
});

// adding multer
const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: function(req, file, cb){
        cb(null, Date.now() + path.extname(file.originalname));
    }
});

const upload = multer({storage: storage});

app.post("/images/add", upload.single("imageFile"), (req, res) =>{
    res.redirect("/images");
});

app.get("/images", function(req, res){
    fs.readdir(path.join(__dirname, "./public/images/uploaded"), function(err, files){
        let obj = {};
        obj.images = [];
        files.forEach(file => {
            obj.images.push(file);
        })
        res.json(obj);
    });
});

// create employees page with other routes
app.get("/employees", function(req, res){
    if(req.query.status){
        data.getEmployeesByStatus(req.query.status).then((data)=>{
            res.json(data);
        }).catch(function(err){
            res.json({message:err});
        })
    } else if (req.query.department){
        data.getEmployeesByDepartment(req.query.department).then((data)=>{
            res.json(data);
        }).catch(function(err){
            res.json({message:err});
        })
    } else if (req.query.manager){
        data.getEmployeesByManager(req.query.manager).then((data)=>{
            res.json(data);
        }).catch(function(err){
            res.json({message:err});
        })
    } else {
        data.getAllEmployees().then((data) => {
            res.json(data);
        }).catch(function(err){
            res.json({message:err});
        });
    }
});

// get an employee page by employee number
app.get("/employee/:value", (req, res)=>{
    data.getEmployeeByNum(req.params.value).then((data) => {
        res.json(data);
    }).catch(function(err){
        res.json({message:err});
    })
})

// create managers page
app.get("/managers", function(req, res){
    data.getManagers().then((data) => {
        res.json(data);        
    }).catch(function(err){
        res.json({message:err});
    });    
});

// create departments page
app.get("/departments", function(req, res){
    data.getDepartments().then((data) => {
        res.json(data);
    }).catch(function(err){
        res.json({message:err});
    });
});

// create a customize error404 page
app.use((req,res) => {
    res.status(404).sendFile(path.join(__dirname, "/views/error404.html"));
});

// have the app listen to the specific port and call the onHTTPStart function
// and display an error message if the program failed to start the server
data.initialize().then(function(){
    app.listen(HTTP_PORT, onHTTPStart);
}).catch(function(err){
    console.log("Unable to start server: ", err);
})