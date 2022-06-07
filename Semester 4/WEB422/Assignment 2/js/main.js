/*********************************************************************************
* WEB422 – Assignment 2
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students. *
* Name: ____YiHsun Lee____ Student ID: ___129713202___ Date: ____2022 May 26___ *
********************************************************************************/

let tripData = [];
let currentTrip = {};
let page = 1;
let perPage = 10;
let map = null;
let tableRows = _.template(`
    <% trips.forEach(trip => { %>
        <tr data-id="<%- trip._id %>" class="<%- trip.usertype %>">
            <td><%- trip.bikeid %></td>
            <td><%- trip["start station name"] %></td>
            <td><%- trip["end station name"] %></td>
            <td><%-(trip.tripduration/60).toFixed(2)%></td>
        </tr>
    <% }); %>
`);

function loadTripData(){
    fetch(`https://web422a1-ylee.herokuapp.com/api/trips?page=${page}&perPage=${perPage}`).then(res=>res.json()).then(data=>{
        tripData = data;
        let tableRow = tableRows({trips: data});
        $("#trips-table tbody").html(tableRow);
        $("#current-page").html(page);
    });
}

$(function(){  
    loadTripData();
    $("#trips-table tbody").on("click", "tr", function(e){
        let id =$(this).attr("data-id");
        currentTrip = _.find(tripData, function(trip){
            return trip._id == id;
        });

        $("#trip-modal .modal-title").html(`Trip Details (Bike:${currentTrip.bikeid})`);
        $("#map-details").html(`<p><strong>Start Location: </strong>${currentTrip["start station name"]}</p>
                                <p><strong>End Location: </strong>${currentTrip["end station name"]}</p>
                                <p><strong>Duration: </strong>${(currentTrip.tripduration/60).toFixed(2)} Minutes</p>`)
        $("#trip-modal").modal({
            backdrop:"static"
        });
    });

    $("#previous-page").on("click", function(e){
        if(page > 1){
            page--;
            loadTripData();
        }
    });

    $("#next-page").on("click", function(e){
        page++;
        loadTripData();
    });

    $('#trip-modal').on('shown.bs.modal', function(){
        map = new L.Map('leaflet', { 
            layers: [
                new L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png')
            ]
        });
        
        let start = L.marker([currentTrip["start station location"].coordinates[1], currentTrip["start station location"].coordinates[0]]).bindTooltip(currentTrip["start station name"],
        {
            permanent: true, direction: 'right'
        }).addTo(map);
        
        let end = L.marker([currentTrip["end station location"].coordinates[1], currentTrip["end station location"].coordinates[0]]).bindTooltip(currentTrip["start station name"],
        {
            permanent: true, direction: 'right'
        }).addTo(map);
    
        var group = new L.featureGroup([start, end]); 
        map.fitBounds(group.getBounds(), { padding: [60, 60] });
    });

    $("#trip-modal").on('hidden.bs.modal', function(){
        map.remove();
    })
});