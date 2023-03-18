set serveroutput on
declare
pl_gpa studenttable.gpa%TYPE;
max_gpa studenttable.gpa%TYPE:=0;
x number(1);
begin
FOR x in 1..5
 LOOP
    select gpa
    into pl_gpa
    from studenttable
    where rollno=x;

    IF pl_gpa> max_gpa THEN
    max_gpa := pl_gpa;
    END IF;
    
    END LOOP;
    dbms_output.put_line('Max GPA: '||max_gpa);

  
end;
/