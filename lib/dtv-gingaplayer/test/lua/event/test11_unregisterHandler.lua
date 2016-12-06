-- Tests registering three handlers and then unregistering the second one

require 'testSystem.testSystem'

local cant = 0

function handlerOne(evt)
  if evt.class == "key" then return end

  if evt.class == "ncl" and evt.action == "start" then
    assertEquals(cant, 0)
  end
  cant = cant + 1
end

function handlerTwo(evt)
  if evt.class == "key" then return end

  assertTrue(false, "Se esperaba que no se llame al handlerTwo despues de eliminar su registracion")
end
 
function handlerThree(evt)
  if evt.class == "key" then return end
  
  if evt.class == "ncl" and evt.action == "start" then
    assertEquals(cant, 1)
  end
end

event.register(1, handlerOne)
event.register(2, handlerTwo)
event.register(3, handlerThree)
event.unregister(handlerTwo)