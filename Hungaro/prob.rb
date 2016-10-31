m = [
[ 48, 48, 50, 44],
[ 56, 60, 60, 68],
[ 96, 94, 90, 85],
[ 42, 44, 54, 46]
]

def printa m
	for i in m
		puts i.to_s
	end
end

def menorl mat
	i = mat[0]
	for j in mat
		if j < i
			i = j
		end
	end
	return i
end

def trans m
	ret = []
	for i in 0..(m.size() -1)
		ret[i] = []
		for j in 0..(m[i].size()-1)
			ret[i][j] = m[j][i]
		end
	end
	
	return ret

end


for i in 0..(m.size() - 1)
	men = menorl m[i]
	for j in 0..(m[i].size() -1)
		m[i][j] = m[i][j] - men
	end
end

m = trans m

for i in 0..(m.size() - 1)
	men = menorl m[i]
	for j in 0..(m[i].size() -1)
		m[i][j] = m[i][j] - men
	end
end

m = trans m

printa m

