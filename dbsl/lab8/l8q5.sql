set serveroutput on
declare
stud_row StudentTable%ROWTYPE;
x number(1) :=1;
begin
WHILE X<6
 LOOP
    select gpa
    into stud_row.gpa
    from studenttable
    where rollno=x;
    IF stud_row.gpa >0 AND stud_row.gpa< 4 THEN
    update studenttable set lettergrade='F' where rollno=x;
    ELSIF stud_row.gpa>=4 AND stud_row.gpa<5 THEN
    update studenttable set lettergrade='E' where rollno=x;
    ELSIF stud_row.gpa>=5 AND stud_row.gpa<6 THEN
    update studenttable set lettergrade='D' where rollno=x;
    ELSIF stud_row.gpa>=6 AND stud_row.gpa<7 THEN
   update studenttable set lettergrade='C' where rollno=x;
    ELSIF stud_row.gpa>=7 AND stud_row.gpa<8 THEN
    update studenttable set lettergrade='B' where rollno=x;
    ELSIF stud_row.gpa>=8 AND stud_row.gpa<9 THEN
    update studenttable set lettergrade='A' where rollno=x;
    ELSE 
    update studenttable set lettergrade='A+' where rollno=x;
    END IF;
    x:=x+1;
    

    END LOOP;

  
end;
/