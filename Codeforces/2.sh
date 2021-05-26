awk 'BEGIN { RS=""; FS="\n"; 
print "Name\t\tHouse No\t\tPhone" } 
{print $1,"\t",$2,"\t" ,$3 }'