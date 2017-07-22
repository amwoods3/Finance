The Calendar class is mainly working so far. From here, we will have to start
working on a class to keep track of finances. The goal is to keep track of
spending of a period of time, then keep track of averages over a certain time,
then use that to determine expenses of each type per day/week/month/year.

If I spent $45 on food one day, then a week later buy $45 again, then the
average for one week would be $45 (assuming that I didn't have any food left).

Finding the average amount I would be spending on a specific thing would
be to find how often I rebuy this type to replace it.

TODO:
Add tests for:

Add functionality:
    Current Currency system is not flexible (we could have Australian Dollars
    (AUD) which would have the same symbol as USD '$' or even Canadian Dollars.
    We need a separation from currency and symbol. If there were a FACTORY for
    the money, and the factory could determine the currency type, and create
    money from the easy way.
