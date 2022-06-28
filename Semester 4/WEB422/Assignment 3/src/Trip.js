import {useState, useEffect} from 'react';
import {Link, useParams} from 'react-router-dom';
import { MapContainer, TileLayer, Marker, Tooltip } from 'react-leaflet';
import { Button, Card, Form } from 'react-bootstrap';
import { useNavigate } from 'react-router-dom';

export default function Trip(){
    const {id} = useParams();
    const[trip, setTrip] = useState(null);
    const[loading, setLoading] = useState(true);
    const navigate = useNavigate();

    useEffect(()=>{
        setLoading(true);

        fetch(`https://web422a1-ylee.herokuapp.com/api/trips/${id}`).then(res=>res.json()).then(result =>{
            if(result.hasOwnProperty("_id")){
                setTrip(result);
            } else{
                setTrip(null);
            }
            setLoading(false);
        });
    },[id]);

    const handleSubmit = (e) => {
        e.preventDefault();
        fetch(`https://web422a1-ylee.herokuapp.com/api/trips/${id}`, {
            method: 'PUT',
            body: JSON.stringify(trip),
            headers:{"Content-Type": "application/json"}
        }).then(res=>res.json()).then(()=>{
            navigate("/trips");
        });
       
    }

    const handleChange = (e) => {
        const target = e.target;
        let value = target.value;
        const name = target.name;
        setTrip(trip =>{
            return {...trip,[name]:value};
        })
    }

    if(loading){
        return(
            <>
                <p>Loading Trip data...</p>
            </>
        );
    } else {
        if(trip){
            return(
                <>
                    <Card>
                        <Card.Body>
                            <Card.Title>Bike: {trip.bikeid} ({trip.usertype})</Card.Title>
                            <Card.Text>
                                {trip['start station name']} - {trip['end station name']}
                            </Card.Text>
                        </Card.Body>
                    </Card>
                    <br/>
                    <MapContainer style={{ "height": "400px" }} center={[trip['start station location'].coordinates[1], trip['start station location'].coordinates[0]]} zoom={15}>
                        <TileLayer url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png" />
                        <Marker position={[trip['start station location'].coordinates[1], trip['start station location'].coordinates[0]]}>
                            <Tooltip permanent direction='right'>Start: {trip['start station name']}</Tooltip>
                        </Marker>
                        <Marker position={[trip['end station location'].coordinates[1], trip['end station location'].coordinates[0]]}>
                            <Tooltip permanent direction='right'>End: {trip['end station name']}</Tooltip> 
                        </Marker>
                    </MapContainer>
                        <br/>
                        <Form onSubmit={handleSubmit}>
                            <Form.Group>
                                <Form.Label>Bike ID</Form.Label>
                                <Form.Control type="number" name="bikeid" value={trip.bikeid} onChange={handleChange}/>
                            </Form.Group>
                            <Form.Group>
                                <Form.Label>Birth Year</Form.Label>
                                <Form.Control type="number" name="birth year" value={trip['birth year']} onChange={handleChange}/>
                            </Form.Group>
                            <Form.Check
                                type="radio"
                                label="Subscriber"
                                name="usertype"
                                value="Subscriber"
                                id="subscriber"
                                checked={trip.usertype === "Subscriber"}
                                onChange={handleChange}
                            />
                            <Form.Check
                                type="radio"
                                label="Customer"
                                name="usertype"
                                value="Customer"
                                id="customer"
                                checked={trip.usertype === "Customer"}
                                onChange={handleChange}
                            />
                            <hr />
                            <Link to="/Trips" className="btn btn-secondary float-right ml-1">Back to Trips</Link>
                            <Button type="submit" className="float-right">Update Trip User</Button>
                        </Form>
                </>
            )
        } else {
            return(
                <>
                    <Card>
                        <Card.Body>
                            <Card.Text>
                                Unable to find Trip with id: {id}
                            </Card.Text>
                        </Card.Body>
                    </Card>
                </>
            )
        }
    }
}