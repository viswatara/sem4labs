set serveroutput on
declare
stud_row StudentTable%ROWTYPE;
x number(1) :=1;
begin
 LOOP
     select gpa
    into stud_row.gpa
    from StudentTable
    where rollno=x;
    
    IF stud_row.gpa >0 AND stud_row.gpa< 4 THEN
    dbms_output.put_line('Grade: F');
    ELSIF stud_row.gpa>=4 AND stud_row.gpa<5 THEN
    dbms_output.put_line('Grade: E');
    ELSIF stud_row.gpa>=5 AND stud_row.gpa<6 THEN
    dbms_output.put_line('Grade: D');
    ELSIF stud_row.gpa>=6 AND stud_row.gpa<7 THEN
    dbms_output.put_line('Grade: c');
    ELSIF stud_row.gpa>=7 AND stud_row.gpa<8 THEN
    dbms_output.put_line('Grade: B');
    ELSIF stud_row.gpa>=8 AND stud_row.gpa<9 THEN
    dbms_output.put_line('Grade: A');
    ELSE 
    dbms_output.put_line('Grade: A+');
    END IF;
    x:=x+1;
    IF x>5 THEN EXIT;
    END IF;

    END LOOP;

  
end;
/