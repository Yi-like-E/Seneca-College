import { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import {Badge, Card, Pagination, Table} from 'react-bootstrap';

export default function Trips(){

    const [trips, setTrips] = useState(null);
    const [page, setPage] = useState(1);
    const [loading, setLoading] = useState(true);
    const navigate = useNavigate();

    useEffect(()=>{
        setLoading(true);
        fetch(`https://web422a1-ylee.herokuapp.com/api/trips?page=${page}&perPage=10`).then(res=>res.json()).then(result =>{
            setTrips(result);
            setPage(page);
            setLoading(false);
        })

    },[page]);

    function previousPage(){
        if(page > 1){
            setPage(page => page-1);
        }
    }

    function nextPage(){
        setPage(page => page + 1)
    }

    if(loading){
        return(
            <>
                <p>Loading Trips...</p>
            </>
        );
    } else{
        return(
            <>
                <Card>
                    <Card.Body>
                        <Card.Title>Trips List</Card.Title>
                        <Card.Text>
                            Full list of Citibike Trips
                            <div className="float-right">
                                <Badge className="Subscriber">Subscriber</Badge>
                                {' '}
                                <Badge className="Customer">Customer</Badge>
                            </div>
                        </Card.Text>
                    </Card.Body>
                </Card>
                <br/>
                <Table bordered hover>
                    <thead>
                        <tr>
                        <th>Bike ID</th>
                        <th>Start Station</th>
                        <th>End Station</th>
                        <th>Duration</th>
                        </tr>
                    </thead>
                    <tbody>
                        {
                            trips.map((trip)=>(
                                <tr className={trip.usertype} key={trip._id} onClick={(e)=>{navigate(`/trip/${trip._id}`)}}>
                                    <td>{trip.bikeid}</td>
                                    <td>{trip['start station name']}</td>
                                    <td>{trip['end station name']}</td>
                                    <td>{(trip.tripduration/60).toFixed(2)}</td>
                                </tr>
                            ))
                        }
                    </tbody>
                </Table>
                <Pagination>
                    <Pagination.Prev onClick={()=>previousPage()}/>
                    <Pagination.Item>{page}</Pagination.Item>
                    <Pagination.Next onClick={()=>nextPage()}/>
                </Pagination>
            </>
        );
    }
}


