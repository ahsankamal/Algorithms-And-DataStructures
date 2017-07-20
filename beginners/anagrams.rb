# Write a function that will find all the anagrams of a word from a given list (array of words). You should return an empty array if there is no anagram. 

def anagrams(word, words)
hash={}
('a'..'z').each {|i| hash[i] = 0}
word.each_char {|i| hash[i]+=1 }

words.collect do |w|
  tmp={}
  ('a'..'z').each {|i| tmp[i] = 0}
  w.each_char {|i| tmp[i]+=1 }
  w if tmp==hash
end.compact 
end


print anagrams('abbabc', ['aabbbc', 'ababcc', 'bbaabc', 'ababac']) 
puts ""
print anagrams('racer', ['crazer', 'carer', 'racar', 'caers', 'racer']) 