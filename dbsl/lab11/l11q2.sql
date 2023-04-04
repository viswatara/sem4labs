create table Old_Data_Instructor(ID varchar(5), name varchar(20), dept_name	varchar(20), 
salary	numeric(8,2));
set serveroutput on 
CREATE OR REPLACE TRIGGER l11q2 
AFTER
    UPDATE 
ON Instructor
FOR EACH ROW
BEGIN 
    insert into Old_Data_Instructor values(:NEW.ID,:NEW.name,
    :NEW.dept_name,:NEW.salary);
END;
/
update instructor set salary=200000 where name='Brandt';
select * from Old_data_instructor;
