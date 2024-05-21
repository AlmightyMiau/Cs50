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
-- Ruth->     Less than 10 min after crime, thief gets in car and leaves in bakery parking lot; Check Bakery Parking Lot cams
-- Eugene->   Eugene knows the thief; Thief withdrew money from ATM on Legget Street
-- Raymond->  Thief made a call <1 min in length after the crime; Thief said they would take first flight out of Fiftyville on 7/29/2023 (day after crime); Accomplice bought ticket after crime (7/28/2023 after 10:15)

-- Check data of Bakery Parking Lot cams
.schema bakery_security_logs

-- Check activity and license plate of bakery cams on 7/28/2023 from 10:05 to 10:25
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 05
AND minute <= 25
AND activity LIKE "exit";
-- License Plates to Check | 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55

-- Does the table people have license plates?
.schema people
-- Yes; also has phone, passport

-- What data is in atm transactions
.schema atm_transactions

-- Check ATM withdrawal on Legget Street on 7/28/2023
SELECT account_number, amount
FROM atm_transactions
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";
-- account_number:amount | 28500762:48, 28296815:20, 76054385:60, 49610011:50, 16153065:80, 25506511:20, 81061156:30, 26013199:35