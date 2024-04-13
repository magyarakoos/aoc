f = (m) -> 
map(l -> match(r"(\d+),(\d+),(\d+)", l), readlines("input"))
