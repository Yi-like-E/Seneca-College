/************************************************************************ *********
* WEB322 – Assignment 04
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students. *
* Name: ____YiHsun Lee___ Student ID: _129713202_ Date: ___2021/July/06___ *
* Online (Heroku) Link: _____https://mighty-sierra-89111.herokuapp.com______
* ********************************************************************************/

var express = require("express");
var app = express(); // to access all the libraries that express provides
var path = require("path"); // to accept files
const data = require("./data-service.js"); // responsible to read json files
const multer = require("multer");
const fs = require("fs");
const bodyParser = require("body-parser");
const exphbs = require('express-handlebars');

app.use(express.static('public')); // to access css site.css
app.use(express.urlencoded({extended: true})); // bodyParser module
// set up handlebar and helper functions
app.engine('.hbs', exphbs({ extname: '.hbs' , helpers:{
    navLink: function(url, options){ 
        return '<li' + ((url == app.locals.activeRoute) ? ' class="active" ' : '') + '><a href="' + url + '">' + options.fn(this) + '</a></li>'; 
    },
    equal: function (lvalue, rvalue, options) { 
        if (arguments.length < 3){
            throw new Error("Handlebars Helper equal needs 2 parameters"); 
        }
        if (lvalue != rvalue) {
            return options.inverse(this); 
        } else {
            return options.fn(this); 
        }
    }
}
}));
app.set('view engine', '.hbs');
app.use(function(req,res,next){
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, ""); 
    next();
});


var HTTP_PORT = process.env.PORT || 8080;

function onHTTPStart(){
    console.log("Express http server is listening on PORT: " + HTTP_PORT);
};

// create the home page
app.get("/", function(req, res){
    res.render("home");
});

// create an about page
app.get("/about", function(req, res){
    res.render("about");
});

// create an addEmployee page
app.get("/employees/add", function(req, res){
    res.render("addEmployee");
});

app.post("/employees/add", (req, res)=>{
    data.addEmployee(req.body).then(() =>{
        res.redirect("/employees");
    })
})

// create an addImage page
app.get("/images/add", function(req, res){
    res.render("addImage");
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
        });
        res.render("images", obj);
    });
});

// create employees page with other routes
app.get("/employees", function(req, res){
    if(req.query.status){
        data.getEmployeesByStatus(req.query.status).then((data)=>{
            res.render("employees", {employees:data});
        }).catch(function(err){
            res.render({message: "no results"});
        })
    } else if (req.query.department){
        data.getEmployeesByDepartment(req.query.department).then((data)=>{
            res.render("employees", {employees:data});
        }).catch(function(err){
            res.render({message: "no results"});
        })
    } else if (req.query.manager){
        data.getEmployeesByManager(req.query.manager).then((data)=>{
            res.render("employees", {employees:data});
        }).catch(function(err){
            res.render({message: "no results"});
        })
    } else {
        data.getAllEmployees().then((data) => {
            res.render("employees", {employees:data});
        }).catch(function(err){
            res.render({message: "no results"});
        });
    }
});

// get an employee page by employee number
app.get("/employee/:value", (req, res)=>{
    data.getEmployeeByNum(req.params.value).then((data) => {
        res.render("employee", {employee:data})
    }).catch(function(err){
        res.render({message: "no results"});
    })
})

// update employee page
app.post("/employee/update", (req, res) => { 
    data.updateEmployee(req.body).then(()=>{
        res.redirect("/employees");
    });
});


// create departments page
app.get("/departments", function(req, res){
    data.getDepartments().then((data) => {
        res.render("departments", {departments:data});
    }).catch(function(err){
        res.render({message:"no results"});
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