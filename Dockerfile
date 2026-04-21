#Build
FROM alpine:latest AS builder

WORKDIR /app

COPY . .

RUN apk add --no-cache build-base && gcc --static employeePayrollSystem.c -o main

#Deploy
FROM scratch	

WORKDIR /app

COPY --from=builder /app/main .

CMD ["./main"]


