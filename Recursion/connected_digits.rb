# ┌───┬───┬───┐
# │ 1 │ 2 │ 3 │
# ├───┼───┼───┤
# │ 4 │ 5 │ 6 │
# ├───┼───┼───┤
# │ 7 │ 8 │ 9 │
# └───┼───┼───┘
#     │ 0 │
#     └───┘
# each of the digits is connected to its adjacent digit (horizontally or vertically, but not diagonally). 
# digit 5 is connected to [2,4,6,8]
# any two connected digits can be replaced with each other.

#print all possible pin numbers

$all_pins=[]
def get_pins(observed)#returns an array of all variations
key_pad = {}
key_pad[1]=[1,2,4]
key_pad[2]=[2,1,5,3]
key_pad[3]=[3,2,6]
key_pad[4]=[4,1,5,7]
key_pad[5]=[5,2,4,6,8]
key_pad[6]=[6,3,5,9]
key_pad[7]=[7,4,8]
key_pad[8]=[8,5,7,9,0]
key_pad[9]=[9,8,6]
key_pad[0]=[0,8]
	$all_pins=[]
	ans = []
    pins(observed.to_s,0,observed.to_s.length, key_pad, ans)
    # print $all_pins.sort
    $all_pins.sort
end

def pins(observed,i,len, key_pad, ans)
if 	i==len
	$all_pins << ans.join
	return
end 
	key_pad[observed[i].to_i].each do |j|
	ans.push(j)
	pins(observed,i+1,len, key_pad, ans)
	ans.pop
	end
end

#Test cases:
print get_pins('8') 
# ["0", "5", "7", "8", "9"]
puts ""

print get_pins('369') 
#["236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339", "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659", "666", "668", "669", "696", "698", "699"]


puts ""
print get_pins('12')
#["11", "12", "13", "15", "21", "22", "23", "25", "41", "42", "43", "45"]