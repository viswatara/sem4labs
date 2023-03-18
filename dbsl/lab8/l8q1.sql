set serveroutput on
declare
stud_row StudentTable%ROWTYPE;
begin
    select gpa,rollno
    into stud_row.gpa, stud_row.rollno
    from StudentTable
    where rollno='&r';

    dbms_output.put_line('GPA :' ||stud_row.gpa|| '  Roll no: '||stud_row.rollno);

end;
/
