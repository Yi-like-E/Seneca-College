-- Q1 SOLUTION -- 
CREATE TABLE l5_movies (
m_id NUMBER PRIMARY KEY,
title VARCHAR2(35) NOT NULL,
release_year NUMBER NOT NULL,
director_id NUMBER NOT NULL,
score NUMBER(3,2) DEFAULT 2.5 CHECK (score BETWEEN 1 AND 4));

CREATE TABLE l5_actors (
a_id NUMBER PRIMARY KEY, 
first_name VARCHAR2(20) NOT NULL,
last_name VARCHAR2(30) NOT NULL);

CREATE TABLE l5_castings (
movie_id NUMBER REFERENCES l5_movies(m_id) ON DELETE CASCADE, -- needed for later truncating l5_directors
actor_id NUMBER REFERENCES l5_actors(a_id),
PRIMARY KEY (movie_id, actor_id));

CREATE TABLE l5_directors (
director_id NUMBER PRIMARY KEY,
first_name VARCHAR2(20) NOT NULL,
last_name VARCHAR2(30) NOT NULL);


-- Q2 SOLUTION -- 
ALTER TABLE l5_movies
ADD FOREIGN KEY (director_id) 
REFERENCES l5_directors(director_id)
ON DELETE CASCADE; -- needed for later truncating l5_directors


-- Q3 SOLUTION -- 
ALTER TABLE l5_movies
ADD UNIQUE (title);


-- Q4 SOLUTION --
TRUNCATE TABLE l5_directors CASCADE; --alternative is to drop/disable the constraint on any child table and then issue a TRUNCATE


-- Q5 SOLUTION -- 
DROP TABLE l5_castings;
DROP TABLE l5_actors;
DROP TABLE l5_movies;
DROP TABLE l5_directors;

/* 
The order of table removal can be important. When a table is
referenced by one or more child tables through foreign key constraints, 
the child table(s) must be deleted before the parent table to maintain
referential integrity. The order of dropping tables, however, does not
matter if the foreign key(s) are dropped. 
*/
