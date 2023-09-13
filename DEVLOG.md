
## 1.9.23
#### Lefteri
- Copied over the socket code and tried to get it to loop, right now it accepts multiple connects to that port and loops but kills each connection after they send.
- Next, hoping to get it to fold into a function somehow without blocking or returning empty stuff, not completely sure.
#### Juniper
- code for generating any number of random points with /dev/urandom

#### Wenjia
- sorted the logic for server - client communication

## 1.10.23
#### Lefteri
- Moved into its own function, discussed how the clients can send back data
- Talked to Mr. K about not using select and figuring out how to use the sockets correctly..
- Implemented socket without select and added port closing stuff from the select code
- Plan to split the main server into 2, one of which is constantly looking for connects and new data and the other has a pipe to it that blocks when reading. This second one is the one that adds up the totals and divides them for the end total, in a while loop. Pushing now for end of school

#### Wenjia
- Modified header + README style, starting client
- Setup basic client files

## 1.11.23
#### Juniper
- added laptop SSH key onto cs lab network to facilitate connecting via exec
- formatted and combined DEVLOG.md; now in main branch as well

#### Wenjia
- Added forking in client
- looked into execvp w ssh

## 1.12.23
#### Juniper
- finished Monte Carlo method calculation
- taught Wenjia how to solve a merge conflict

#### Wenjia
- Working on socket client side

#### Lefteri
- Got socket client side sending data, but server interprets wrong(I think, weird issues)
- Server interprets correctly now - client just needs to do points calculations and we are basically there, now just need way to auto distribute code to computers

## 1.13.23
#### Lefteri
- Finally got server client connection stuff working
- Decided on sending just number inside and using constant number of points total

## 1.15.23
#### Juniper
- function to ssh from marge to any lap computer and remotely executes client program

#### Wenjia
- Wrote forking on client-side; added ARGS for points/size modification
- Added diagnostic prints & comments: [MONTE] from monte, [PARENT] [CHILD] from forking within client.c, [SOCKET - CLIENT] & [SOCKET - SERVER] within client.c and final.c respectively.

#### Lefteri
- Figured out need to use marge ip instead of local host for demo

## 1.16.23
#### Juniper
- debugging: now looping the right number in distribute
- debugging: sprintf for ssh
- struggled with leftover bugs

#### Lefteri
- Worked on ssh but could not figure out
- Worked on bug stuck reading nothing but could not figure out
