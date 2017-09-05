This application is used to keep track of personal financial activity.
It is a bare bones application that can keep track of money coming in,
money going out, etc.

Using the application

to compile the program run 'make' in the command prompt.
to run the program run 'make r' in the command prompt.

The application is seperated into accounts that keep track of individual
activity.

For example, say you have a budget that you are keeping track of food spending.
You want to make sure that you regulate your budget on food.
Then you could create an account like so (starting out with $150.00):

>>> create food USD 150.00

This will create the account for handling food. Now, say that you went to
an Indian restaurant and you spent $15.80 on food there. You can then
tell the program

>>> food take 15.80 "eat at Indian restaurant"

and it will subtract $15.80 from your food account.

If you want to show the transactional history of food, you can do that by
saying:

>>> food show

then, it will show the transaction history of food for you.

If you want to add money to food then you can do this:

>>> food add $50 'Add budget from pay'

This will give you the ability to add money to the food account. (You may
want to take from another account that food got the money from).

After you have finished with the activity, lets say you want to save it.
The following command saves:
>>> save

If you rerun the program, then you may want to reload food again so that you
can edit its activity.
The following command loads food:
>>> load food

