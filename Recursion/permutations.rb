#Print all uniq permutations of given string

#using built-in function
#string = "1234"
#string.chars.permutation.map(&:join).uniq

#using algorithm
$all_perm=[]
def permutations(string)
	$all_perm=[]
  	perm(string,0,string.size)
  	$all_perm.uniq.sort
end

def perm(str,i,n)
	# puts str
	if i==n-1
		$all_perm << "#{str}" #can't use $all_perm << str
		return
	end
	j=i
	while j<=n-1
		str[i],str[j] = str[j],str[i]
		perm(str,i+1,n)
		str[i],str[j] = str[j],str[i]
		j+=1
	end	
end

print permutations('123')
#["123", "132", "213", "231", "312", "321"]
puts ""
print permutations('abcda')
#["aabcd", "aabdc", "aacbd", "aacdb", "aadbc", "aadcb", "abacd", "abadc", "abcad", "abcda", "abdac", "abdca", "acabd", "acadb", "acbad", "acbda", "acdab", "acdba", "adabc", "adacb", "adbac", "adbca", "adcab", "adcba", "baacd", "baadc", "bacad", "bacda", "badac", "badca", "bcaad", "bcada", "bcdaa", "bdaac", "bdaca", "bdcaa", "caabd", "caadb", "cabad", "cabda", "cadab", "cadba", "cbaad", "cbada", "cbdaa", "cdaab", "cdaba", "cdbaa", "daabc", "daacb", "dabac", "dabca", "dacab", "dacba", "dbaac", "dbaca", "dbcaa", "dcaab", "dcaba", "dcbaa"]