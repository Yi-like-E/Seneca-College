-- ***********************
-- Name: YiHsun Lee
-- ID: 129713202
-- Date:02/04/2021
-- Purpose: Lab 03 DBS211
-- ***********************

-- Q1 SOLUTION --
CREATE TABLE L5_MOVIES(
    m_id NUMBER,
    title VARCHAR2(35) NOT NULL,
    release_year NUMBER NOT NULL,
    director_id NUMBER NOT NULL,
    score NUMBER(3,2) DEFAULT 2.5, 
    CONSTRAINT pk_m_id
    PRIMARY KEY (m_id),
    CONSTRAINT check_score CHECK (score > 0 AND score < 5)
);

CREATE TABLE L5_ACTORS (
    a_id NUMBER,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    CONSTRAINT pk_a_id
    PRIMARY KEY (a_id)
);

CREATE TABLE L5_CASTINGS(
    movie_id NUMBER,
    actor_id NUMBER,
    CONSTRAINT pk_movie_id_actor_id
    PRIMARY KEY(movie_id, actor_id),
    CONSTRAINT fk_movie_id
    FOREIGN KEY(movie_id)
    REFERENCES L5_MOVIES(m_id),
    CONSTRAINT fk_actor_id
    FOREIGN KEY(actor_id)
    REFERENCES L5_ACTORS(a_id)
);

CREATE TABLE L5_DIRECTORS(
    director_id NUMBER,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    CONSTRAINT pk_director_id
    PRIMARY KEY (director_id)
);

-- Q2 SOLUTION --
ALTER TABLE L5_MOVIES
ADD CONSTRAINT fk_director_id
FOREIGN KEY (director_id) 
REFERENCES L5_DIRECTORS(director_id);

-- Q3 SOLUTION --
ALTER TABLE L5_MOVIES
ADD CONSTRAINT uq_title
UNIQUE (title);

-- Q4 SOLUTION --
ALTER TABLE L5_MOVIES
DROP CONSTRAINT fk_director_id;
ALTER TABLE L5_DIRECTORS
DROP CONSTRAINT pk_director_id;
TRUNCATE TABLE L5_DIRECTORS; 

-- Q5 SOLUTION --
/*
a. 
DROP TABLE L5_CASTINGS Cascade Constraints;
DROP TABLE L5_DIRECTORS Cascade Constraints;
DROP TABLE L5_ACTORS Cascade Constraints;
DROP TABLE L5_MOVIES Cascade Constraints;

b.
Yes. The order of removing tables is important because of the constraints that each table have.
So it is best to drop L5_CASTINGS first since it is related to L5_MOVIES and L5_ACTORS through the foreign
key, and by breaking most of the connections at once will make it easier to drop other tables afterwards.
L5_DIRECTORS is connected to L5_DIRECTORS, thus, by dropping L5_DIRECTORS, it removes the relationship between
these two tables. And finally, we can drop L5_ACTORS and L5_MOVIES accordingly without worrying about the
constraints as all the related constraints have been dropped already.
*/