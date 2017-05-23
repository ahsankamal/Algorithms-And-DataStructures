def powerset(nums)
  bool = [false]*nums.length
  all_subsets = []
  generate(nums,0,nums.length,bool,all_subsets)
  print all_subsets
  all_subsets
end
def generate(arr,i,n,bool,all_subsets)
  if i==n
     set=[]
     arr.each_with_index {|i,j| set<<i if bool[j] }
     all_subsets << set
     # print set
     return 
  end    
  [false,true].each do |k|
    bool[i] = k
    generate(arr,i+1,n,bool,all_subsets)
  end 
end

powerset([1,2,3,4])