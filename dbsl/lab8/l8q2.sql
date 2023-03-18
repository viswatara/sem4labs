set serveroutput on
declare
stud_row StudentTable%ROWTYPE;
begin
 

    select gpa
    into stud_row.gpa
    from StudentTable
    where rollno='&r';
    
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


end;
/