This is an application meant for keeping track of money usage over a period of
time. It is currently under development, and has many features still yet to
come.

What the application can do so far:

The Account class has been created, so the application has the ability to
create accounts. An account is an amount of money together in one area
(analygous to a bank account). For example, if one has a budget for eating out
they can create an account called "Eat Out Budget". Then the program will be
able to keep track of how much money they have to eat out with.

=====================================================================
What needs to be added (or worked on):
=====================================================================

Account takes a Money instance when adding or subtracting an amount, which
requires you to have a MoneyFactory outside of Account that Account already
has. This is redundant and should not be necessary. Therefore, we need to
create methods for adding and taking money from the Account with a string.

Account cannot start with a negative amount, should we make it possible for
account to start with a negative amount?

Account sould have a way to view transaction history. Kind of like how an
account for a bank has a transaction history.

We want to be able to represent the amount of money in the account and have a
quick and easy way to represent if it is negative. Maybe we can have a function
that returns a string for the amount and adds a '-' in the front if it is
negative.

Tests for functions are lacking, we need to write more. (To add a test, one must
go to the Test directory and add a file "TestXYZ" where XYZ is the name of the
class that is being tested. If the file already exists, then adding a test for
that class has the following convention (in this project):
test_CLASSNAME_FUNCTIONNAME
When writing tests, try to see if the result is what you expected by comparing
to expected results. 
).
