/************************************************************************ *********
* WEB322 – Assignment 06
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students. *
* Name: ____YiHsun Lee___ Student ID: _129713202_ Date: ___2021/August/03___ *
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
const dataServiceAuth = require("./data-service-auth.js");
const clientSessions = require("client-sessions");

app.use(clientSessions({
    cookieName: "session",
    secret:"web322assignment6_unguessableStringByYiHAHAHA",
    duration: 2*60*1000,
    activeDuration: 1000*60
}));

app.use(function(req, res, next){
    res.locals.session = req.session;
    next();
});

function ensureLogin(req, res, next){
    if(!req.session.user){
        res.redirect("/login");
    } else{
        next();
    }
}

app.use(express.static('public')); // to access css site.css
app.use(bodyParser.urlencoded({extended: true})); // bodyParser module
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
app.get("/employees/add", ensureLogin,function(req, res){
    data.getDepartments().then((data) =>{
        res.render("addEmployee", {departments: data});
    }).catch((err) =>{
        res.render("addEmployee", {departments: []});
    })
});

app.post("/employees/add", ensureLogin,(req, res)=>{
    data.addEmployee(req.body).then(() =>{
        res.redirect("/employees");
    }).catch((err) =>{
        res.render("Unable to add employee");
    })
})

// create an add department page
app.get("/departments/add", ensureLogin,function(req, res){
    res.render("addDepartment");
});

app.post("/departments/add", ensureLogin,(req, res)=>{
    data.addDepartment(req.body).then(() =>{
        res.redirect("/departments");
    }).catch((err) =>{
        res.render("Unable to add department");
    })
})

// create an addImage page
app.get("/images/add", ensureLogin,function(req, res){
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

app.post("/images/add", upload.single("imageFile"), ensureLogin,(req, res) =>{
    res.redirect("/images");
});

app.get("/images", ensureLogin,function(req, res){
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
app.get("/employees", ensureLogin,function(req, res){
    if(req.query.status){
        data.getEmployeesByStatus(req.query.status).then((data)=>{
            if(data.length > 0){
                res.render("employees", {employees:data});
            } else{
                res.render("employees", {message:"no results"});
            }
        }).catch(function(err){
            res.render({message: "no results"});
        })
    } else if (req.query.department){
        data.getEmployeesByDepartment(req.query.department).then((data)=>{
            if(data.length > 0){
                res.render("employees", {employees:data});
            } else{
                res.render("employees", {message:"no results"});
            }
        }).catch(function(err){
            res.render({message: "no results"});
        })
    } else if (req.query.manager){
        data.getEmployeesByManager(req.query.manager).then((data)=>{
            if(data.length > 0){
                res.render("employees", {employees:data});
            } else{
                res.render("employees", {message:"no results"});
            }
        }).catch(function(err){
            res.render({message: "no results"});
        })
    } else {
        data.getAllEmployees().then((data) => {
            if(data.length > 0){
                res.render("employees", {employees:data});
            } else{
                res.render("employees", {message:"no results"});
            }
        }).catch(function(err){
            res.render({message: "no results"});
        });
    }
});

// get an employee page by employee number
app.get("/employee/:value", ensureLogin,(req, res)=>{
    let viewData = {};
    data.getEmployeeByNum(req.params.value).then((data) =>{
        if(data){
            viewData.employee = data;
        } else{
            viewData.employee = null;
        }
    }).catch(()=>{
        viewData.employee = null;
    }).then(data.getDepartments)
    .then((data) =>{
        viewData.departments = data;
        for(let i = 0; i < viewData.departments.length; i++){
            if(viewData.departments[i].departmentId == viewData.employee.department){
                viewData.departments[i].selected = true;
            }
        }
    }).catch(()=>{
        viewData.departments = [];
    }).then(() =>{
        if(viewData.employee == null){
            res.status(404).send("Employee Not Found");
        } else{
            res.render("employee", {viewData: viewData});
        }
    }).catch((err) =>{
        res.render("Unable to retrieve requested employee");
    })
});

// delete an employee from employee number
app.get("/employees/delete/:empNum", ensureLogin,(req, res) =>{
    data.deleteEmployeeByNum(req.params.empNum).then(() =>{
        res.redirect("/employees")
    }).catch(function(err){
        res.status(500).send("Unable to Remove Employee / Employee not found");
    });
})

// delete a department from department id
app.get("/departments/delete/:deptId", ensureLogin,(req, res) =>{
    data.deleteDepartmentById(req.params.deptId).then(() =>{
        res.redirect("/departments")
    }).catch(function(err){
        res.status(500).send("Unable to Remove Department / Department not found");
    });
})

// get a department page by department id
app.get("/department/:departmentId", ensureLogin,(req, res)=>{
    data.getDepartmentById(req.params.departmentId).then((data) => {
        if(data.length > 0){
            res.render("department", {department:data})
        } else{
            res.status(404).send("Department Not Found");
        }
    }).catch(function(err){
        res.status(404).send("Department Not Found");
    })
})

// update employee page
app.post("/employee/update", ensureLogin,(req, res) => { 
    data.updateEmployee(req.body).then(()=>{
        res.redirect("/employees");
    }).catch((err) =>{
        res.status(500).send("Unable to Update Employee");
    });
});

// create departments page
app.get("/departments", ensureLogin,function(req, res){
    data.getDepartments().then((data) => {
        if(data.length > 0){
            res.render("departments", {departments:data});
        } else{
            res.render("departments", {message:"no results"});
        }
    }).catch(function(err){
        res.render({message:"no results"});
    });
});

// update department page
app.post("/department/update", ensureLogin,(req, res) => { 
    data.updateDepartment(req.body).then(()=>{
        res.redirect("/departments");
    }).catch((err) =>{
        res.status(500).send("Unable to Update Department");
    });
});

// create login page
app.get("/login", (req, res)=>{
    res.render("login");
})

app.post("/login", (req, res)=>{
    req.body.userAgent = req.get("User-Agent");
    dataServiceAuth.checkUser(req.body).then((user)=>{
        req.session.user={
            userName: user.userName,
            email: user.email,
            loginHistory: user.loginHistory
        }
        res.redirect("/employees");
    }).catch((err) =>{
        res.render("login", {errorMessage: err, userName: req.body.userName});
    });
})

// create register page
app.get("/register", (req, res)=>{
    res.render("register");
})

app.post("/register", (req, res)=>{
    dataServiceAuth.registerUser(req.body).then(()=>{
        res.render("register", {successMessage: "User created"});
    }).catch((err)=>{
        res.render("register", {errorMessage: err, userName: req.body.userName});
    })
})

// create logout page
app.get("/logout", (req, res)=>{
    req.session.reset();
    res.redirect("/");
})

// create userHistory page
app.get("/userHistory", ensureLogin, (req, res)=>{
    res.render("userHistory");
})

// create a customize error404 page
app.use((req,res) => {
    res.status(404).sendFile(path.join(__dirname, "/views/error404.html"));
});

// have the app listen to the specific port and call the onHTTPStart function
// and display an error message if the program failed to start the server
data.initialize()
.then(dataServiceAuth.initialize)
.then(function(){
    app.listen(HTTP_PORT, onHTTPStart);
}).catch(function(err){
    console.log("Unable to start server: " + err);
});