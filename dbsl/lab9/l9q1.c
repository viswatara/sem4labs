create table salary_raise(
    instructor_id number,
    raise_date date,
    raise_amt number);

set serveroutput on
declare
cursor c(dname instructor.dept_name%type) is select * from instructor where dept_name=dname for update;
dname instructor.dept_name%type;
begin
    dname:='&dept_name';
for bk in c(dname) loop
update instructor set salary=salary*1.5 where 
current of c;
if c%found then dbms_output.put_line(c%rowcount||'rows updated');
insert into salary_raise values( bk.id,current_date,(0.05)*bk.salary );
end if;
end loop;
end;
/
