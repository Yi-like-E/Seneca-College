import {Card} from 'react-bootstrap';

export default function About(){
    return(
        <>
            <Card>
                <Card.Body>
                    <Card.Title>About</Card.Title>
                    <Card.Text>
                        My name is YiHsun Lee, the author of this web app.
                    </Card.Text>
                </Card.Body>
            </Card>
            <p>This citibike web app is built on the react and can display the sample data retrieves from heroku api.</p> 
            <p>Further more, this web app allows user to modify the bike ID and birth year while incorporating leaflet to show the trip on an interactive map.</p>
            <p>To contact me, please email <a href="mailto:ylee212@myseneca.ca">ylee212@myseneca.ca</a></p>
        </>
    )
}