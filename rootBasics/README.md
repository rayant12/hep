# ExamplesForStudents/rootbasics

# If you want to create a class to read your own TTree, supposely if your TTree name is "EventData"
```
root -l eventdata.root
```
Then, within ROOT:
```
EventTree->MakeClass("myClass")
```

A header file "myClass.h" and a .C file "myClass.C" will be created. To run myClass:

```
root -l 
.L myClass.C
myClass t
t.Loop()
```