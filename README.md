This is an application meant for keeping track of money usage over a period of
time. It is currently under development, and has many features still yet to
come.

What the application can do so far:

The Account class has been created, so the application has the ability to
create accounts. An account is an amount of money together in one area
(analygous to a bank account). For example, if one has a budget for eating out
they can create an account called "Eat Out Budget". Then the program will be
able to keep track of how much money they have to eat out with.

What needs to be added (or worked on):

The Account class currently has problems working with negative amounts.

The Transaction class doesn't handle problems like $53.27 - $64.20 (it will end
up saying one has tons of money after this, which doesn't happen in real life).

The Money class operators do not preserve currency type and symbol as well if
the currency is broken up into smaller portions (such as dollars and cents).
For example, if we say USD$(50.00) - USD$(30.00) the result money type doesn't
know that it is USD and it doesn't know to display a $ or to break up into
larger and smaller parts so would be displayed as "2000" which has no meaning
on its own. Also, this problem escalates to not being able to operate on
a money instance created this way: USD$(50.00) - USD$(30.00) + USD$(15.00) will
throw an error because of Money mismatch.

Tests for functions are lacking, we need to write more.
