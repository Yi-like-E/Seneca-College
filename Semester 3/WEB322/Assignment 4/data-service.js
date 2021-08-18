const fs = require("fs");
let employees = [];
let departments = [];

module.exports.initialize = function(){
    return new Promise((resolve, reject) => {
        fs.readFile('./data/employees.json', (err, data) => {
            if(err){
                reject(err);
            }
            employees = JSON.parse(data);
        }); 
        fs.readFile('./data/departments.json', (err, data) => {
            if(err){
                reject(err);
            }
            departments = JSON.parse(data);
        });
        resolve();
    });
}

module.exports.getAllEmployees = function(){
    return new Promise((resolve, reject) => {
        if(employees.length == 0){
            reject("No data to be displayed");
        }
        resolve(employees); 
    }); 
}

module.exports.getDepartments = function(){
    return new Promise((resolve, reject) => {
        if(departments.length == 0){
            reject("No data to be displayed");
        }
        resolve(departments); 
    }); 
}

module.exports.getManagers= function(){
    return new Promise((resolve, reject) => {
        var managers = [];
        for(let i = 0; i < employees.length; i++){
            if(employees[i].isManager == true){
                managers.push(employees[i]);
            }
        }
        if(managers.length == 0){
            reject("No managers to be displayed");
        }
        resolve(managers);
    });
}

/* ---------------------------------- */
/* ---------- Assignment 3 ---------- */
/* ---------------------------------- */
module.exports.addEmployee = function(employeeData){
    return new Promise((resolve, reject) =>{
        if(!employeeData){
            reject("No data to be added");
        }
        employeeData.isManager = (employeeData.isManager)? true: false;
        employeeData.employeeNum = employees.length + 1;
        employees.push(employeeData);
        resolve();
    })
}

module.exports.getEmployeesByStatus = function(status){
    return new Promise((resolve, reject) =>{
        var employeeStatus = [];
        employees.forEach(employee =>{
            if(employee.status == status){
                employeeStatus.push(employee);
            }
        });
        if(employeeStatus.length == 0){
            reject("No results returned");
        }
        resolve(employeeStatus);
    })
}

module.exports.getEmployeesByDepartment = function(department){
    return new Promise ((resolve, reject) =>{
        var employeeDep = [];
        employees.forEach(employee =>{
            if(employee.department == department){
                employeeDep.push(employee);
            }
        });
        if(employeeDep.length == 0){
            reject("No results returned");
        }
        resolve(employeeDep);
    })
}

module.exports.getEmployeesByManager = function(manager){
    return new Promise ((resolve, reject) =>{
        var employeeList = [];
        employees.forEach(employee =>{
            if(employee.employeeManagerNum == manager){
                employeeList.push(employee);
            }
            
        });
        if(employeeList.length == 0){
            reject("No results returned");
        }
        resolve(employeeList);
    })
}

module.exports.getEmployeeByNum = function(num){
    return new Promise ((resolve, reject) =>{
        var employeeByNum;
        employees.forEach(employee =>{
            if(employee.employeeNum == num){
                employeeByNum = employee;
            }
        });
        if(!employeeByNum){
            reject("No results returned");
        }
        resolve(employeeByNum);
    })
}

/* ---------------------------------- */
/* ---------- Assignment 4 ---------- */
/* ---------------------------------- */
module.exports.updateEmployee = function(employeeData){
    return new Promise((resolve, reject) =>{
        let flag = false;
        for(let i = 0; i < employees.length; i++){
            if(employees[i].employeeNum == employeeData.employeeNum){
                employees[i] = employeeData;
                flag = true;
            }
        }
        if(!flag){
            reject("No results returned");
        }
        resolve();
    })
}