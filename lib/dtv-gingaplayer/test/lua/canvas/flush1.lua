-- Testea #flush cu�ndo se lo env�a a un canvas que no es el principal
local subCanvas = canvas:new(200,200)
local subSubCanvas = canvas:new(100,100)
subSubCanvas:attrColor("green")
subSubCanvas:drawRect("fill",0,0,100,100)
subCanvas:attrColor("red")
subCanvas:drawRect("fill",0,0,200,200)
subCanvas:compose(0,0,subSubCanvas)
-- canvas:compose(0,0,subCanvas)
subCanvas:flush()