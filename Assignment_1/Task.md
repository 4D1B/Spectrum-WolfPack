# change management in dataset
1. We have two datasets -
1a. data__2019-11-28.csv which is a set of data (one data in one row) for November 28, 2019. We will call this set V1
1b. data__2019-11-29.csv which is another set of data (one data in one row) for November 29, 2019. We will call this set V2
2. There are changes between V1 and V2. It is like that V2 is an incremental update on V1
3. We need to generate a V3 where V1 is updated with the changes in V2
4. The idea is to find out what will be the fastest way to do this and then code it

## New tasks

1. How many rows ??
2. Unique policy numbers.
3. How many male / female.