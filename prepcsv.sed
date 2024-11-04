# Remove commas within fields
s/, / /g

# Remove quotation marks
s/"//g

# Remove the first column
s/[^,]*,//

# Remove the 'debit/credit' column
s/^\([^,]*,[^,]*,\)[^,]*,/\1/
