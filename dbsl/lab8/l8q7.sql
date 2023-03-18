set serveroutput on
declare
pl_gpa studenttable.gpa%TYPE;
g varchar(2);
x number(1) :=1;

begin
 <<mainloop>>
 
        select gpa
        into pl_gpa
        from StudentTable
        where rollno=x;
    
    IF pl_gpa >0 AND pl_gpa< 4 THEN
    g:='F';
    
   
    ELSIF pl_gpa>=4 AND pl_gpa<5 THEN
     g:='E';

    ELSIF pl_gpa>=5 AND pl_gpa<6 THEN
     g:='D';

    ELSIF pl_gpa>=6 AND pl_gpa<7 THEN
     g:='C';
    
    ELSIF pl_gpa>=7 AND pl_gpa<8 THEN
    g:='B';
   
    ELSIF pl_gpa>=8 AND pl_gpa<9 THEN
     g:='A';
    ELSE 
     g:='A+';
    
    END IF;
    dbms_output.put_line('Roll no:' ||x|| ' Grade: '||g);
    x:=x+1;
    IF x<=5 THEN
     GOTO mainloop;
    END IF;

   
    

  
end;
/