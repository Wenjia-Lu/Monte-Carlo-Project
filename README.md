# Project Info

# We will find the area of a circle (and as additions other, more intresting shapes) using the monte carlo method, inscribing the shape in a square, picking random points, and seeing the ratio within the shape vs outside. That problem can be divided up into many smaller problems, by passing off sets of points to check to other computers.

# You define the shape, using different parameters based on the shape, and if possible later for complex shapes entering coordinates, or possibly even a visual interface to draw with, though that would be significantly more difficult. The program will then output the estimate for the area, mabye updating the estimate as more information comes in.

# Technical Design

Topics covered in class in the project:
- Allocating memory
  - Creating variables, storing the data for the trials, etc
- Processes
  - Forking for main server to be able to work with several different clients across machine, as well as forking on each machine for multithreading
- Pipes
  - On each individual machine, the client will fork after it has recieved its set of problems so it can multithread
- Sockets
  - A server will distribute the work between other machines, which will need to be done over sockets

#Project Breakdown & Design

## Server
Handling the input from user, interpreting it into the shapes, and dealing with conenctions to the clients then distributing the work

## Clients
Connecting to the server and recieving the work it needs to do
Splitting up into multiple processes, subdividing the work further
Recombining that info and sending it back

## Breakup
June handling the math aspects for server and shapes

Lefty doing dividing work up between computers, sockets

Wenjia doing client forking/multithreading and data stuff


# Algorithms/Data Structures

-Monte Carlo method, using a large number of random points and finding the ratio of those points inside vs outside a shape, and using that to find the area

# A timeline with expected completion dates of parts of the project.

A basic forking server, with a client that takes tasks and returns them and being able to run very basic shapes (circle) by TUESDAY
Multithreading, splitting up and distributing out the job to several computers by FRIDAY
Any additional cool stuff for TUESDAY(17th)

# Instructions
- open a terminal to run server:
  - make 
  - make run
- open another terminal to run client:
  - make client
- Now server should print its calculations in terminal. Multiple clients can be ran.

# Working/ Not working:
- Bug where doing make run multiple times make server spam data without listening.
- Server SSH did not end up working.
