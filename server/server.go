package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func indexHandler(c *gin.Context) {
	c.String(http.StatusOK, "hello index")
}

func main() {
	router := gin.Default()

	router.GET("/", indexHandler)

	//8888 8889 8890
	//20000-30000
	router.Run(":21000")
}
