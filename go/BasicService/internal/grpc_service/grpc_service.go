package grpc_service

import (
	my_best_service "MyBestService/internal/transport"
)

type GrpcService struct {
	sensorsStorage my_best_service.MyBestServiceServer
	_token         string
}

func NewGrpcService(sensorsStorage my_best_service.MyRequest, addr string, token string) *my_best_service.MyResponse {
	return &my_best_service.MyResponse{}
}
