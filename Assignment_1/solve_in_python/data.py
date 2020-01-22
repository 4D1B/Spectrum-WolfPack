import csv
with open('data__2019-11-28.csv', newline='') as csvfile:
    spamreader = csv.DictReader(csvfile)
    
    uniq={}
    i=0
    mCount=0
    fCount=0
    for row in spamreader:
        policyNumber=row['policyNumber']
        if policyNumber in uniq:
            continue
        uniq[policyNumber]=i
        i=i+1

        gender=row['gender']
        if gender=="FEMALE":
            fCount=fCount+1
        elif gender=="MALE":
            mCount=mCount+1

    print("unique policy number: ",i)
    print("male count: ", mCount, " & female count: ", fCount)