/************************************************************************ *********
* WEB322 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students. *
* Name: ____YiHsun Lee___ Student ID: _129713202_ Date: ___2021/June/03___ *
* Online (Heroku) Link: _____https://mighty-sierra-89111.herokuapp.com______
* ********************************************************************************/

var express = require("express");
var app = express(); // to access all the libraries that express provides
app.use(express.static('public'));
var path = require("path"); // to accept files
const data = require("./data-service.js"); // responsible to read json files
app.use(express.static('public/css')); // to access css site.css

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

// create employees page
app.get("/employees", function(req, res){
    data.getAllEmployees().then((data) => {
        res.json(data);
    }).catch(function(err){
        res.json({message:err});
    });
});

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