# Lab_5
1. Parameters that affect the behavior of the simulation. 
- time of day;
- if an employee is absent at the place of work;
- if the queue ticket machine is broken;
- if the ATM is broken;


2. Insights of the simulation runtime. 
- how much time did the simulation take;
- how many customers there were;
- how many of them were men;
- how many of them were women;
- how many of the customers were at the customer department;
- how many of the customers were at the insurance department;
- how many of the customers were at the credit department;
- how many of the customers were at the investment department;
- how many lei were taken from the ATM;
- how many euros were changed in lei;


A detailed description of the work:

1. I have taken into account the given suggestion from the laboratory nr. 4. That is, to use the naming conventions of the C++ programming language;

2. I implemented the continuous simulation. I did this by using the while() loop.

3. I changed the code to show the time when the customer enters the bank, which eventually will help in giving some insights about the simulation. In the simulation, it is considered that for each minute from 8 to 12 PM a person will enter the bank with a probability of 30%. For 12 to 14 PM with a probability of 40%. For 14 to 17 PM with a probability of 50%.

4. In addition, I implemented the idea that an employee may not be at his/her place of work. For instance, s/he took a break. In this case, the customer would have to wait.

5. Also, I created the option for the machines to be broken. That is, for the ATM and the Queue Ticket Machine. In this case, until the machine is repaired, the customer would have to wait.

6. Moreover, I added a feature to make the simulation slower when is generated.

7. Then, I created some variables that would be able to represent some insights of the simulation mentioned above.
