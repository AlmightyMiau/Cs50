-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find out what tables I can use to find information
.tables

-- What can I find in the crime_scene_reports table?
.schema crime_scene_reports

-- Find the report from July 28, 2023 and on Humphrey Street
SELECT description
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = "Humphrey Street";
-- crime at 10:15; Check Interviews with three people present, all mention the bakery;

-- What can I find ihn the interviews?
.schema interviews

-- Look for names of interviews on 7/28/2023
SELECT name
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;
-- There are more than just three here

-- Look for names of interviews on 7/28/2023 that mention the bakery
SELECT name
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";
-- Names are Ruth, Eugene, and Raymond

-- Check transcript of all three interviews
SELECT name, transcript
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";
-- Ruth->     Less than 10 min after crime, thief gets in car in bakery parking lot; Check Bakery Parking Lot cams
-- Eugene->   Eugene knows the thief; Thief withdrew money from ATM on Legget Street
-- Raymond->  Thief made a call <1 min in length after the crime; Thief said they would take first flight out of Fiftyville on 7/29/2023 (day after crime); Accomplice bought ticket after crime (7/28/2023 after 10:15)

-- Check data of Bakery Parking Lot cams
.schema bakery_security_logs

-- Check activity and license plate of bakery cams on 7/28/2023 from 10:05 to 10:25
SELECT activity, license_plate
FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 5
AND minute <= 25;
