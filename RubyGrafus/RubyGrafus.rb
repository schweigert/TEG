class Graph
	
	def initialize name
		@name = name
		@vertices = Hash.new
	end
	
	def link a b
		@vertices[a] ||= []
		@vertices[a] << b
	end

	
end



