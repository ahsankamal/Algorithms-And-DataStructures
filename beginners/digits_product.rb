
# Given an integer product, find the smallest positive integer the product of whose digits is equal to given product. If there is no such integer, return -1 instead.

def digits_product(product)
    digits=[]
    if product<10
    	return product+10
    end
	9.downto(2).each do |i| #find all factors starting from 9 down to 2 and then reverse them to get the smallest positive integer whose digit's product is equal to the given number
	while product%i == 0
		digits<<i
		product=product/i
	end
end
	if product > 10 #means given number has a prime factor greater than 10. 
		return -1
	end	
	digits.reverse.join
end
	
	print digits_product(100)
	puts ""
	print digits_product(1000)