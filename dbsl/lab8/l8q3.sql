set serveroutput on
declare
    issue_date date;
    return_date date;
begin
    issue_date:='&i';
    return_date:='&r';

    IF return_date-issue_date<=7 THEN
    dbms_output.put_line('Fine: NIL');
    ELSIF return_date-issue_date>7 AND return_date-issue_date<16 THEN
    dbms_output.put_line('Fine: Rs. '||1*(return_date-issue_date));
    ELSIF return_date-issue_date>15 AND return_date-issue_date<31 THEN
    dbms_output.put_line('Fine:Rs. '||2*(return_date-issue_date));
    ELSE 
    dbms_output.put_line('Fine:Rs. '||5*(return_date-issue_date));
   END IF;
end;
/
