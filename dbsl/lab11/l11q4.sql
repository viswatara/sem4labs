create table client_master(client_no number(5),Cname varchar(20),
Caddress varchar(20), Bal_due number(5));
create table audiclient(client_no number(5),Cname varchar(20), Bal_due number(5),stat VARCHAR(15),USERID VARCHAR(4) default('0000'), opsdate date);

insert into client_master values(1,'TARA','Hyderabad',10000);
insert into client_master values(2,'LAXYA','Delhi',20000);
insert into client_master values(3,'HARI','Kolakata',30000);
set serveroutput on 

CREATE OR REPLACE TRIGGER l11q4
BEFORE
    UPDATE or DELETE OR INSERT
ON client_master
FOR EACH ROW
BEGIN 
    CASE
    WHEN INSERTING THEN
    insert into audiclient values(:new.client_no,:new.Cname,
    :new.bal_due,'INSERT',NULL,CURRENT_TIMESTAMP);
    WHEN UPDATING THEN
    insert into audiclient values(:OLD.client_no,:OLD.cname,
    :OLD.bal_due,'UPDATE',NULL,CURRENT_TIMESTAMP);
    WHEN DELETING THEN
    insert into audiclient values(:OLD.client_no,:OLD.cname,
    :OLD.bal_due,'DELETE',NULL,CURRENT_TIMESTAMP);
    END CASE;
END;
/
 insert into client_master values(4,'LAYA','HYd',40000);
 select * from audiclient;