awk 'BEGIN{FS=","}
{if($4>=60){a[$1]=a[$1]+1}}
END{for(val in a){if(a[val]>1){print(val)}}}'