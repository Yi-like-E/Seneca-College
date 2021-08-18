/* ---------------------------------- */
/* ---------- Assignment 5 ---------- */
/* ---------------------------------- */
const Sequelize = require('sequelize');

var sequelize = new Sequelize('drcorp0iuv80b', 'spmrvhcltihcla', 
'd46c87ec638c9891203b399dd0f089a22e3651a14a521391c6f156983b1906bd',{
    host: 'ec2-35-174-56-18.compute-1.amazonaws.com',
    dialect: 'postgres',
    port: 5432,
    dialectOptions:{
        ssl:{rejectUnauthorized: false}
    },
    query:{raw: true}
});

// create Employee table
var Employee = sequelize.define('Employee',{
    employeeNum:{
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    firstName: {
        type: Sequelize.STRING
    },
    lastName:{
        type: Sequelize.STRING
    },
    email:{
        type: Sequelize.STRING
    },
    SSN:{
        type: Sequelize.STRING
    },
    addressStreet:{
        type: Sequelize.STRING
    },
    addressCity:{
        type: Sequelize.STRING
    },
    addressState:{
        type: Sequelize.STRING
    },
    addressPostal:{
        type: Sequelize.STRING
    },
    maritalStatus:{
        type: Sequelize.STRING
    },
    isManager:{
        type: Sequelize.BOOLEAN
    },
    employeeManagerNum:{
        type: Sequelize.INTEGER
    },
    status:{
        type: Sequelize.STRING
    },
    department:{
        type: Sequelize.INTEGER
    },
    hireDate:{
        type: Sequelize.STRING
    }
});

// create Department table
var Department = sequelize.define('Department',{
    departmentId:{
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    departmentName: {
        type: Sequelize.STRING
    }
});

module.exports.initialize = function(){
    return new Promise((resolve, reject) =>{
        sequelize.sync().then(() =>{
            resolve();
        }).catch(() =>{
            reject("unable to sync the database");
        })
    })
}

module.exports.addDepartment = function(departmentData){
    return new Promise((resolve, reject) =>{
        for(var i in departmentData){
            if(departmentData[i] == ''){
                departmentData[i] = null;
            }
        }
        Department.create(departmentData).then(() =>{
            resolve();
        }).catch((err) =>{
            reject("unable to create department");
        })
    })
}

module.exports.updateDepartment = function(departmentData){
    return new Promise((resolve, reject) =>{
        for(var i in departmentData){
            if(departmentData[i] == ''){
                departmentData[i] = null;
            }
        }
        Department.update(departmentData, {
            where:{
                departmentId: departmentData.departmentId
            }
        }).then(() =>{
            resolve();
        }).catch((err) =>{
            reject("unable to update department");
        })
    })
}

module.exports.getDepartmentById = function(id){
    return new Promise ((resolve, reject) =>{
        Department.findAll({
            where:{
                departmentId: id
            }
        }).then(function(data){
            resolve(data);
        }).catch((err) =>{
            reject("no results returned");
        })
    })
}

module.exports.deleteEmployeeByNum = function(empNum){
    return new Promise((resolve, reject) =>{
        Employee.destroy({
            where:{
                employeeNum: empNum
            }
        }).then(() =>{
            resolve();
        }).catch((err) =>{
            reject("Unable to delete employee");
        })
    })
}

module.exports.deleteDepartmentById = function(deptId){
    return new Promise((resolve, reject) =>{
        Department.destroy({
            where:{
                departmentId: deptId
            }
        }).then(() =>{
            resolve();
        }).catch((err) =>{
            reject("Unable to delete department");
        })
    })
}

/* ---------------------------------- */
/* --- Update previous functions ---- */
/* ---------------------------------- */
module.exports.getAllEmployees = function(){
    return new Promise((resolve, reject) => {
        Employee.findAll().then(function(data){
            resolve(data);
        }).catch((err) =>{
            reject("no results returned");
        })
    }); 
}

module.exports.getDepartments = function(){
    return new Promise((resolve, reject) => {
        Department.findAll().then(function(data){
            resolve(data);
        }).catch((err) =>{
            reject("no results returned");
        })
    }); 
}

module.exports.addEmployee = function(employeeData){
    return new Promise((resolve, reject) =>{
        employeeData.isManager = (employeeData.isManager) ? true: false;
        for(var i in employeeData){
            if(employeeData[i] == ''){
                employeeData[i] = null;
            }
        }
        Employee.create(employeeData).then(() =>{
            resolve();
        }).catch((err) =>{
            reject("unable to create employee");
        })
    })
}

module.exports.getEmployeesByStatus = function(statusVal){
    return new Promise((resolve, reject) =>{
        Employee.findAll({
            where:{
                status: statusVal
            }
        }).then(function(data){
            resolve(data);
        }).catch((err)=>{
            reject("no results returned");
        })
    })
}

module.exports.getEmployeesByDepartment = function(departmentVal){
    return new Promise ((resolve, reject) =>{
        Employee.findAll({
            where:{
                department: departmentVal
            }
        }).then(function(data){
            resolve(data);
        }).catch((err)=>{
            reject("no results returned");
        })
    })
}

module.exports.getEmployeesByManager = function(managerID){
    return new Promise ((resolve, reject) =>{
        Employee.findAll({
            where:{
                employeeManagerNum: managerID
            }
        }).then(function(data){
            resolve(data);
        }).catch((err) =>{
            reject("no results returned");
        })
    })
}

module.exports.getEmployeeByNum = function(num){
    return new Promise ((resolve, reject) =>{
        Employee.findAll({
            where:{
                employeeNum: num
            }
        }).then(function(data){
            resolve(data[0]);
        }).catch((err) =>{
            reject("no results returned");
        })
    })
}

module.exports.updateEmployee = function(employeeData){
    return new Promise((resolve, reject) =>{
        employeeData.isManager = (employeeData.isManager) ? true: false;
        for(var i in employeeData){
            if(employeeData[i] == ''){
                employeeData[i] = null;
            }
        }
        Employee.update(employeeData, {
            where:{
                employeeNum: employeeData.employeeNum
            }
        }).then(() =>{
            resolve();
        }).catch((err) =>{
            reject("unable to update employee");
        })
    })
}