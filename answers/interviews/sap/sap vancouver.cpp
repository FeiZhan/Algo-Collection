Shape
 <- Circle
 <- Square
 
 
 stack<...>
 
 class ShapeList;
 
 class Undoable {
     /*ShapeList &before;
     ShapeList &after;*/
     ShapeList &target;
 };
 class ColorUndoable : Undoable {
     Color before;
     Color after;
 };
 
stack<Undoable> undo_stack;
stack<Undoable> redo_stack;

// multi-select


// draw something
Undoable undo;
redo_stack.clear();
undo_stack.push(undo);

// hit ctrl+z
if (! undo_stack.empty()) {
    Undoable undo = undo_stack.pop();
    undo.after.clean();
    undo.before.draw();
    redo_stack.push(undo);
}

// hit ctrl+y
if (! redo_stack.empty()) {
    Undoable redo = redo_stack.pop();
    redo.before.clean();
    redo.after.clean();
    undo_stack.push(redo);
}



Shape
 <- Circle
 <- Square
 
 
 stack<...>
 
 class ShapeList;
 
 class Undoable {
     /*ShapeList &before;
     ShapeList &after;*/
     ShapeList &target;
 };
 class ColorUndoable : Undoable {
     Color before;
     Color after;
 };
 
stack<Undoable> undo_stack;
stack<Undoable> redo_stack;

// multi-select


// draw something
Undoable undo;
redo_stack.clear();
undo_stack.push(undo);

// hit ctrl+z
if (! undo_stack.empty()) {
    Undoable undo = undo_stack.pop();
    undo.after.clean();
    undo.before.draw();
    redo_stack.push(undo);
}

// hit ctrl+y
if (! redo_stack.empty()) {
    Undoable redo = redo_stack.pop();
    redo.before.clean();
    redo.after.clean();
    undo_stack.push(redo);
}