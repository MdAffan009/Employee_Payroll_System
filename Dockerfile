#Build
FROM alpine:latest AS builder

WORKDIR /app

COPY . .

RUN apk add --no-cache build-base && gcc employeePayrollSystem.c -o main

#Deploy
FROM alpine:latest	

WORKDIR /app

COPY --from=builder /app/main .

CMD ["./main"]


