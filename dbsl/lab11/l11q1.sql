set serveroutput on 
CREATE OR REPLACE TRIGGER l11q1 
BEFORE 
    UPDATE 
ON Takes
FOR EACH ROW
BEGIN 
    insert into log_change_Takes values(CURRENT_TIMESTAMP,:OLD.ID,:OLD.course_id,
    :OLD.sec_id,:OLD.semester,:OLD.year,:OLD.grade);
END;
/

-create table log_change_Takes(Time_of_Change date,ID
varchar(5),
  2      course_id              varchar(8),
  3      sec_id         varchar(8),
  4      semester               varchar(6),
  5      year                   numeric(4,0),
  6      grade          varchar(2));
   update takes set grade='A+' where id=12345;
    select * from log_change_Takes;
