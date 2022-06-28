import './App.css';
import { Col, Container, Nav, Navbar, Row } from 'react-bootstrap';
import { Navigate, Route, Routes } from 'react-router-dom';
import { LinkContainer } from 'react-router-bootstrap';
import Trips from './Trips';
import Trip from './Trip';
import About from './About';
import NotFound from './NotFound';

function App() {
  return (
    <>
      <Navbar bg="light" expand="lg">
        <LinkContainer to="/">
          <Navbar.Brand>New York Citibike Trips</Navbar.Brand>
        </LinkContainer>
      <Navbar.Toggle aria-controls="basic-navbar-nav" /> 
      <Navbar.Collapse id="basic-navbar-nav">
      <Nav className="mr-auto"> 
        <LinkContainer to="/trips">
          <Nav.Link>Full List</Nav.Link> 
        </LinkContainer> 
        <LinkContainer to="/about">
          <Nav.Link>About</Nav.Link> 
        </LinkContainer>
      </Nav> 
      </Navbar.Collapse>
      </Navbar>
      <br /> 
      <Container> 
        <Row>
          <Col>
            <Routes>
              <Route path="/" element={<Navigate to="/trips" />}/>
              <Route path="/trips" element={<Trips />} />
              <Route path="/trip/:id" element={<Trip />} />
              <Route path="/about" element={<About />} />
              <Route path="*" element={<NotFound />} />
            </Routes>
          </Col> 
        </Row>
      </Container> 
      <br /><br />
    </>
  );
}

export default App;
