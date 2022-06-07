/************************************************************************ *********
* WEB422 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students. *
* Name: ___YiHsun Lee___ Student ID: __129713202__ Date: __May 13, 2022__
* Heroku Link: ____https://web422a1-ylee.herokuapp.com____
* ********************************************************************************/

const express = require("express");
const app = express();
const cors = require("cors");
const TripDB = require("./modules/tripDB.js");
const db = new TripDB();

const HTTP_PORT = process.env.PORT || 8080;

app.use(cors());
app.use(express.json());

app.get("/", (req, res)=>{
    res.json({message: "API Listening"});
});

app.post("/api/trips", (req, res)=>{
    db.addNewTrip(req.body).then(newTrip =>{
        res.status(201).json({message: `Trip with id: ${newTrip.id} is created.`});
    }).catch((err) =>{
        res.status(400).json({message: err});
    })
});

app.get("/api/trips", (req, res)=>{
    db.getAllTrips(req.query.page, req.query.perPage).then(trips=>{
        res.status(200).json(trips);
    }).catch((err)=>{
        res.status(400).json({message: err});
    })
});

app.get("/api/trips/:id", (req, res) =>{
    db.getTripById(req.params.id).then(trip =>{
        // if(trip){
        //     res.status(200).json(trip);
        // } else{
        //     res.status(404).json({message: `Trip with id: ${req.params.id} is not found.`})
        // }
        res.status(200).json(trip);
    }).catch((err) =>{
        res.status(404).json({message: err});
    });
});

app.put("/api/trips/:id", (req, res)=>{
    db.updateTripById(req.body, req.params.id).then(() =>{
        res.status(200).json({message: `Trip with id: ${req.params.id} is updated.`});
    }).catch((err) =>{
        res.json({message:err});
    })
});

app.delete("/api/trips/:id", (req, res) =>{
    db.deleteTripById(req.params.id).then(() =>{
        res.status(200).json({message: `Trip with id: ${req.params.id} is deleted.`});
    }).catch((err) =>{
        res.status(500).json({message:err});
    });
});

db.initialize("mongodb+srv://ylee:forWeb422A1@cluster0.zox6t.mongodb.net/sample_training?retryWrites=true&w=majority").then(() =>{
    app.listen(HTTP_PORT, () =>{
        console.log(`server listening on: ${HTTP_PORT}`);
    });
}).catch((err) =>{
    console.log(err);
});
